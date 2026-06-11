#include <bits/stdc++.h>
#define pb push_back
#define Int int64_t
using namespace std;
const Int M=(Int)(1e9+7);

inline Int mmul(Int a,Int b){if(a>=M)a=a%M;if(b>=M)b=b%M;if(a*b>=M)return(a*b)%M;return(a*b);}
inline Int madd(Int a, Int b){if(a>=M)a=a%M;if(b>=M)b=b%M;if(a+b>=M)return(a+b)%M;return(a+b);}



int main()
{
    int N;cin>>N;
    string s=to_string(N);
    
    int mp[10][10]={0};
    int ans=0;
    
    for(int i=1;i<=N;++i){
        int last=i%10;
        int t=i;
        while(t>=10){
            t/=10;
        }
        int first=t;
        mp[first][last]++;
    }
    
    for(int i=1;i<=9;++i){
        for(int j=1;j<=9;++j){
            ans+=mp[i][j]*mp[j][i];
        }
    }
    cout<<ans<<"\n";
}