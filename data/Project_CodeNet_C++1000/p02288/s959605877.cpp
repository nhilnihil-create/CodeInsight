#include <iostream>
#include <algorithm>
using namespace std;

int n;
int H[500005];

int main()
{
    cin>>n;
    int i;
    for(i=1;i<=n;i++){cin>>H[i];}
    for(i=n/2;i>0;i--){
        int j=i;
        while(j*2<=n){
            int ma=j*2;
            if(H[j*2+1]>H[j*2]&&j*2+1<=n)ma=j*2+1;
            if(H[j]<H[ma])swap(H[j],H[ma]);
            j=ma;
        }
    }
    for(i=1;i<=n;i++)cout<<" "<<H[i];
    cout<<endl;
    return 0;
}