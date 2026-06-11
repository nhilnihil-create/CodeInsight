#include<bits/stdc++.h>
#define vll vector<ll>
#define vi vector<int>
#define vpll vector<pair<ll,ll>>
#define pii pair<int,int>
#define REP(i,a) for(int (i)=0; (i)<(a); (i)++)
#define RREP(i,a) for(int (i)=a-1; (i)>=(0); (i)--)
#define REP2(i,a,b) for(int (i)=(a); (i)<(b); (i)++)
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
#define m0(x) memset(x,0,sizeof(x))
typedef long long ll;

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string S; cin >> S;
  int N = S.size();
  vector<int> H;
  vector<int> ans(N,0);
  REP2(i,1,N) if(S[i-1] == 'R' && S[i] == 'L') H.push_back(i);
  for(int itr = 0; itr < H.size(); itr++){
    int left = H[itr] - 1;
    int right = H[itr];
    while(1){
      if(left - 1 >= 0 && S[left - 1] == 'R') left--;
      else break;
    }
    while(1){
      if(right + 1 < N && S[right + 1] == 'L') right++;
      else break;
    }
    //cout << left << "->" << H[itr] << "<-" << right << endl;
    for(int j = left; j <= right; j++){
     	 ans[H[itr] - abs(((H[itr] - j)%2))]++;
    }
  }
  
  REP(i,N) cout << ans[i] << " ";

  return 0;
}