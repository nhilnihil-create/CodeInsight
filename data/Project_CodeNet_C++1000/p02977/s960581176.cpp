#include<bits/stdc++.h>
using namespace std;

int f(int n) {
    int ans = 1;
    while (ans*2<=n)    ans*=2;
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    if (n<3 || __builtin_popcount(n) == 1) cout<<"No"<<endl;
    else if (n%4==0) {
        cout<<"Yes"<<endl;
        int a = f(n), b = n-a;


        vector<int> v;
        for (int i=1; i<n; i++)
            if (i!=a && i!=b)   v.push_back(i);

        v.push_back(a);
        v.push_back(b);

        for (int i=1; i<v.size(); i++)  cout<<v[i-1]<<" "<<v[i]<<"\n";
        for (int i=1; i<v.size(); i++)  cout<<n+v[i-1]<<" "<<n+v[i]<<"\n";

        cout<<v.back()<<" "<<n+v[0]<<endl;
        cout<<a<<" "<<n<<endl;
        cout<<b<<" "<<2*n<<endl;
    }
    else if (n%4==2) {
        cout<<"Yes"<<endl;
        for (int i=1; i<n-3; i++)    cout<<i<<" "<<i+1<<"\n";
        cout<<n-3<<" "<<n+1<<endl;
        for (int i=n+1; i<2*n-3; i++)    cout<<i<<" "<<i+1<<"\n";

        cout<<n-2<<" "<<n-1<<"\n";
        cout<<n-1<<" "<<1<<"\n";
        cout<<1<<" "<<2*n-2<<"\n";
        cout<<2*n-2<<" "<<2*n-1<<"\n";
        cout<<n-1<<" "<<n<<"\n";
        cout<<2<<" "<<2*n<<"\n";
    }
    else if (n%4==3) {
        cout<<"Yes"<<endl;
        for (int i=1; i<n; i++)    cout<<i<<" "<<i+1<<"\n";
        cout<<n<<" "<<n+1<<endl;
        for (int i=n+1; i<2*n; i++)    cout<<i<<" "<<i+1<<"\n";
    }
    else if (n%4==1) {
        cout<<"Yes"<<endl;
        for (int i=1; i<n-2; i++)    cout<<i<<" "<<i+1<<"\n";
        cout<<n-2<<" "<<n+1<<endl;
        for (int i=n+1; i<2*n-2; i++)    cout<<i<<" "<<i+1<<"\n";

        cout<<n-1<<" "<<n<<"\n";
        cout<<n<<" "<<1<<"\n";
        cout<<1<<" "<<2*n-1<<"\n";
        cout<<2*n-1<<" "<<2*n<<"\n";
    }
}

