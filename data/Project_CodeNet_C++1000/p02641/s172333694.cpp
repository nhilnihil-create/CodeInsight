#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,n; cin >> x >> n;
    vector<int> p(101,0);
    for(int i=0; i<n; i++){
        int j; cin >> j;
        p[j] = 1;
    }

    int left = x;
    int right = x;
    while(true){
        if(left > 0){
            if(p[left] == 0){
                cout << left << endl;
                break;
            }else{
                left--;
            }
        }else{
            cout << "0" << endl;
            break;
        }

        if(right < 101){
            if(p[right] == 0){
                cout << right << endl;
                break;
            }else{
                right++;
            }
        }else{
            cout << "101" << endl;
            break;
        }
    }
}