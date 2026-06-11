#include <bits/stdc++.h>
using namespace std;

typedef vector< vector<int> > vvi;
typedef vector< vector<bool> > vvb;
typedef vector< vector<char> > vvc;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef long long ll;

int main(){
    int n,k;
    cin >> n >> k;
    vector<double> p(n);
    for(int i=0;i<n;i++){
        double a;
        cin >> a;
        double sum=(1+a)/2;
        p[i]=sum;
    }
    double ans=0;
    for(int i=0;i<k;i++){
        ans+=p[i];
    }
    double temp=ans;
    for(int i=k;i<n;i++){
        temp=temp+(p[i]-p[i-k]);
        ans=max(ans,temp);
    }
    printf("%.10lf\n",ans);
    return 0;

}