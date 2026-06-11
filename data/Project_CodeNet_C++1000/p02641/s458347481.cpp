#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<map>
#include<stack>
#include<iterator>
using namespace std;
typedef long long ll;
int main()
{
    ll num,n,a,vis[109],box,box1;
    cin>>num>>n;
    for(int i=0;i<=102;i++) vis[i]=0;
    for(int i=0;i<n;i++){
        cin>>a;
        vis[a]=1;
    }
    for(int i=num;i<=101;i++){
        if(vis[i]==0){
            box=i;
            break;
        }
    }
    for(int i=num;i>=0;i--){
        if(vis[i]==0){
            box1=i;
            break;
        }
    }
    //cout<<box
    if(abs(num-box)>abs(num-box1)) cout<<box1<<endl;
    if(abs(num-box)<abs(num-box1)) cout<<box<<endl;
    if(abs(num-box)==abs(num-box1)) cout<<min(box1,box)<<endl;
    return 0;
}
