#include<bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define fo(i) for(int i=0;i<=(1e7);++i)
#define Fo(i,k,n) for(int i=k;i<n;++i)
typedef long long int lli;
int main(){
    FIO
    int i,k; cin>>k;
    int total=0;
    int flag=0;
    fo(i){
        total=(total*10+7)%k;//appending the number by 7
        if(total==0)
            {
                cout<<i+1<<endl;
                flag=1;
                break;
            }
    }
      if(flag==0){
            cout<<-1<<endl;
    }
}


