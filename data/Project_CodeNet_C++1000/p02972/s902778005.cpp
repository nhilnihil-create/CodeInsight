#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;cin>>n;
    int a[n];
    for (int i=0;i<n;i++)
        cin>>a[i];
    int b[n]{};
    vector<int> ans;
    for (int i=n-1;i>=0;i--) {
        int c=0;
        for (int j=i+i+1;j<n;j+=i+1)
            c^=b[j];
        b[i]=a[i]^c;
        if (b[i])
            ans.push_back(i+1);
    }
    int m=ans.size();
    cout<<m<<endl;
    for (int i=m-1;i>=0;i--) {
        if (i!=m-1)
            cout<<' ';
        cout<<ans[i];
    }
    return 0;
}