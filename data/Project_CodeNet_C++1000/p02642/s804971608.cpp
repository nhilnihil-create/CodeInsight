#include<iostream>
using namespace std;
int pos[1000001];
#include<cmath>
bool done[1000001];
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int ans=n;

    for(int i=0; i<n; i++) {
        cin>>arr[i];
        pos[arr[i]]++;
        
    }
    for(int i=1; i<=1e6; i++) {
        if(pos[i]>1){ans-=pos[i];
        done[i]=true;}
    }
    if(pos[1]==1)
        cout<<1<<endl;
    else if(pos[1]>1)
        cout<<0<<endl;
    else {
        for(int i=0; i<n; i++) {
            if(!done[arr[i]]) {
                int y=arr[i];
                int l=(int)ceil(sqrt(y));
                for(int j=2; j<=l; j++) {
                    if(y%j==0 && j!=y ) {
                        if(pos[j]>0 || pos[y/j]>0) {
                            ans--;
                            break;
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;


    }
    return 0;
}