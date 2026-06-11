#include <bits/stdc++.h>
using namespace std ;
int main(){
    int N;
    cin >> N;
    int a[N];
    int One=0;
    for(int i=0;i<N;i++){
        cin >> a[i];
        if(a[i]==1){
            One++;
        }
    }
    if(One ==0){
        cout << -1 << endl;
        return 0;
    }
    int count =0;
    int j=0;
    if(N==1){
        if(a[0]==1){
            cout << 0 << endl;
            return 0;
        }else{
            cout << -1 << endl;
            return 0;
        }
    }

    for(int i=1;i<N;i++){
        for(j;j<N;j++){
            if(a[j]==i){
                j=j+1;
                break;
            }
            count++;
        }
    }
    
    cout << count << endl;
}