#include<bits/stdc++.h>
using namespace std;

int main(){
    int x;
    cin >> x;
    int res=x;
    bool flg=true;
    vector<int> prime;
    prime.push_back(2);
    if(x==2){
        cout << 2 << endl;
    }else{
        for(int i=3; i<x; i++){ // エラトステネスの篩
            flg=true;
            for(int j=2; j<i; j++){
                if(i%j == 0){
                    flg = false;
                    break;
                }
            }
            if(flg){
                prime.push_back(i);
            }
        }
        while(true){
            flg = true;
            for(int i=0; i<prime.size(); i++){
                if(x%prime.at(i) == 0){
                    flg = false;
                    break;
                }
            }
            if(flg){
                cout << x << endl;
                break;
            }else{
                x++;
            }
        }
    }
    return 0;
}
