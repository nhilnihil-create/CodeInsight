#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector <int> a(n);
    int maxValue = 0;
    int seconMax = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i]>maxValue){
            //seconMax=maxValue;
            maxValue=a[i];
        }
    }
    int num = 0;
    for(int i = 0; i < n; i++){
        if(a[i]==maxValue){
            num++;
        }else{
            seconMax=max(seconMax,a[i]);
        }
    }
    if(num>1){
        for(int i = 0; i < n; i++){
            cout << maxValue << endl;
        }
    }else{
        for(int i = 0; i < n; i++){
            if(a[i]==maxValue){
                cout << seconMax << endl;
            }else{
                cout << maxValue << endl;
            }
        }
    }
    return 0;
}