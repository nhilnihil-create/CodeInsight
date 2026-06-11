#include <iostream>
using namespace std;

int main(void){
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)cin>>a[i];
    long int scr=1000,cnt=0;

    for (int i = 0; i < n-1; i++)
    {
        cnt=0;
        if(a[i]<a[i+1]){
            cnt=scr/a[i];
            scr+=(a[i+1]-a[i])*cnt;
        }

        //cout<<scr<<endl;
    }
    cout<<scr<<endl;
    
    return 0;
}