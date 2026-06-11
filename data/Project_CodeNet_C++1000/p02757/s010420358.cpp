#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>


using namespace std;

typedef long long ll;
typedef vector<vector<int> > Graph;


int main() {
    int N,P;
    cin>>N>>P;
    string s;
    cin>>s;
    
    ll count=0;
    ll arr[N+1];
    for(int i=0;i!=N;++i)arr[i]=0;
    
    reverse(s.begin(),s.end());
    
    if(P==2||P==5){
        for(int i=0;i!=N;++i){
            if((s[i]-'0')%P==0){
                count+=N-i;
            }
        }
    }else{
        
        
        
        
        ll keta=1;
        ll num=0;
        arr[0]=0;
        for(int i=1;i<=N;++i){
            num+=(s[i-1]-'0')*keta;
            num%=P;
            arr[i]=num;
            keta=keta*10%P;
        }
        
        /* for(int i=0;i<=N;++i)cout<<arr[i];
        cout<<endl;
         */
        
        ll amari[P];
        for(int i=0;i!=P;++i)amari[i]=0;
        
        for(int i=0;i<=N;++i){
            ll tmp=arr[i];
            ++amari[tmp];
        }
        
        for(int i=0;i!=P;++i){
           // cout<<i<<": "<<amari[i]<<endl;
            count+=(amari[i])*(amari[i]-1)/2;
        }
        
    }
    cout<<count<<endl;
}
