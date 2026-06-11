#include <iostream>
#include <cmath>

using namespace std;

double s[1000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    int n;
    while(true) {
        double a=0, m=0;
        cin>>n;
        if(n==0) break;
        for(int i=0; i<n; i++) {
            cin>>s[i];
            m+=s[i];
        }
        m/=n;
        for(int i=0; i<n; i++) {
            a+=(s[i]-m)*(s[i]-m);
        }
        cout<<sqrt(a/n)<<'\n';
    }
    return 0;
}