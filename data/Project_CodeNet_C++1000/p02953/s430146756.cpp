#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define ll long long

int main(){
    int n;
    cin >> n;
    vector<ll> height(n);
    rep(i,n){
        cin >> height.at(i);
    }
    int counter=0;
    bool flag = true;
    for(int i = 1;i < n;i++){
        if(height.at(i)>height.at(i-1)){
            counter = 0;
        }else if(height.at(i)+1<height.at(i-1)){
            flag = false;
            break;
        }else if(height.at(i)+1==height.at(i-1)){
            counter++;
            if(counter == 2){
                flag = false;
                break;
            }
        }
    }

    if(flag){
        cout << "Yes" << endl;
    }else{ 
        cout << "No" << endl;
    }
}
