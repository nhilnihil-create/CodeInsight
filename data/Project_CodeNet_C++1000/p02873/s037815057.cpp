#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
int main(){
    string s;
    cin >> s;
    char cur='a';
    ll right =0;
    ll left = 0;
    ll sum = 0;
    //cout<<s<<endl;

    rep(i,0,s.size()){
        if(cur=='>'&&s[i]=='<'){
            //cout<<"a";
            ll M = max(right,left);
            ll m = min(right,left);
            sum += M*(M+1)/2+(m-1)*m/2;
            right=1;
            left=0;
            cur='<';
        }else{
            //cout<<"w";
            if(s[i]=='<'){
                right++;
                cur='<';
            }else{
                left++;
                cur='>';
            }
        }

    }
    ll M = max(right,left);
    ll m = min(right,left);
    sum += M*(M+1)/2+m*(m-1)/2;

    cout<<sum<<endl;
  return 0;
}