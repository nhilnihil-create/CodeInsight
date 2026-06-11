#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,l;
    cin >> n >> l;

    int check=0;
    if(l<0 && l+n-1<0){
        check=l+n-1;
    }
    else if(l<0){
        check=0;
    }
    else if(l>=0){
        check=l;
    }

    int ans=0;
    for(int i=0;i<n;i++){
        if(check!=l) ans+=l;
        l++;
    }
    cout << ans << endl;
}