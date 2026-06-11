/*
                                                  
  _|_|                              _|  _|    _|  
_|    _|  _|  _|_|  _|_|_|_|        _|  _|  _|    
_|    _|  _|_|          _|          _|  _|_|      
_|    _|  _|          _|      _|    _|  _|  _|    
  _|_|    _|        _|_|_|_|    _|_|    _|    _|  
                                                                                                    
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
//#define ls (rt<<1)
//#define rs (rt<<1|1)
#define vi vector<int>
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;i++)
#define fi first
#define se second
typedef long long ll;
using namespace std;
int main(){
    int n;cin>>n;
    if(n&(n-1)){
        cout<<"Yes"<<endl;
        cout<<"1 2"<<endl<<"2 3"<<endl<<"3 "<<n+1<<endl<<n+1<<' '<<n+2<<endl<<n+2<<' '<<n+3<<endl;
        for(int i=4;i+1<=n;i+=2){
            cout<<"1 "<<i<<endl<<i<<' '<<i+n+1<<endl;
            cout<<"1 "<<i+1<<endl<<i+1<<' '<<i+n<<endl;
        }
        if(n%2==0){
            rep(i,4,n){
                int tmp=i^1^n;
                if(tmp<n&&tmp!=3){
                    cout<<i<<' '<<2*n<<endl<<tmp<<' '<<n;
                    return 0;
                }
            }
        }
    }else{
        cout<<"No";
    }
    return 0;
}