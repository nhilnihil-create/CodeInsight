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
    #define m0(x) memset(x,0,sizeof(x))
    typedef long long ll;
     
    using namespace std;
     
    int main(){
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      int M, D;
      cin >> M >> D;
      int ans = 0;
      REP2(i, 1, M+1){
        REP2(j, 1, D+1){
          int d1 = j%10, d10 = (j/10)%10;
          if(d1 <= 1 || d10 <= 1) continue;
          if(d1 * d10 == i) ans++;
        }
      }
      cout << ans << endl;
      return 0;
    }