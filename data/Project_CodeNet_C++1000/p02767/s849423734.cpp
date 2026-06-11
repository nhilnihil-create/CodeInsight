#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> x(n);
    for(int i=0;i<n;i++){
        cin >> x[i];
    }
    int y=0,box;
    for(int i=1;i<=100;i++){
        box = y;
        for(int j=0;j<n;j++){
                if(j==0){
                    y=0;
                }
                y += (x[j]-i)*(x[j]-i);
        }
        if(i>1){
            y = min(y,box);
        }
    }
    cout << y << endl;
    return 0;
}