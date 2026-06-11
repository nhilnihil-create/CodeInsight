#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a,b;
    cin>>a>>b;
    int n=a.size(),sum=0;
    for(int i =0;i<=n;i++){
        if(a[i] != b[i]){
            sum++;
            }
        }
        cout<<sum<<endl;

    return 0;
}
