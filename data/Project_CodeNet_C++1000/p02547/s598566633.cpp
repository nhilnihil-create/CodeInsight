#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main(){
    int n=0, i=0, d=0;
    cin >> n;

    int roll[n][2];

    for(i=0; i<n; i++){
        cin >> roll[i][0] >> roll[i][1];
    }

    for(i=0; i<n; i++){
        if(roll[i][0]==roll[i][1]){
            d++;
        }
        else{
            d=0;
        }
        if(d==3){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}

