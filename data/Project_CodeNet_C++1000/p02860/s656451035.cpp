#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,d=0;
    char a[100];
    cin >> n;
    cin >> a;
    if(n%2==1){
        cout << "No" << endl;
    }
    else{
        for(i=0;i<n/2;i++){
            if(a[i]==a[i+(n/2)]){
                d++;
            }
        }
        if(d==(n/2)){
            cout << "Yes" << endl;
        }
        else{
            cout << "No\n";
        }
    }

    return 0;
}