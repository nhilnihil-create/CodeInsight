#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int h,w,n;
    cin>>h>>w>>n;
    int mx=max(h,w);
    cout<<(n+mx-1)/mx<<endl;
}