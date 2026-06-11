#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,x;
    cin >> n >> x;
    
    int cnt=0;
    int length=0;
    for(int i=0;i<=n;i++){
        if(length<=x){
            cnt++;   
        }
        int l;
        cin >> l;
        length+=l;
    }

    cout << cnt << endl;
}