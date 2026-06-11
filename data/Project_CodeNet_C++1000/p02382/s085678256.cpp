#include <bits/stdc++.h>
using namespace std;

int main(void) {
    double n,x[100],y[100],ans1=0.0,ans2=0.0,ans3=0.0,ans4=0.0;
    cin>>n;
    vector<double> ans4_a(n,0);
    for(int i=0;i<n;i++) cin>>x[i];
    for(int i=0;i<n;i++) cin>>y[i];
    for(int i=0;i<n;i++) {
        ans1+=abs(x[i]-y[i]);
        ans2+=abs(x[i]-y[i])*abs(x[i]-y[i]);
        ans3+=abs(x[i]-y[i])*abs(x[i]-y[i])*abs(x[i]-y[i]);
        ans4_a[i]=abs(x[i]-y[i]);
    }
    ans4=*max_element(ans4_a.begin(),ans4_a.end());
    printf("%f\n",ans1);
    printf("%f\n",sqrt(ans2));
    printf("%f\n",pow(ans3,1.0/3.0));
    printf("%f\n",ans4);
    return 0;
}