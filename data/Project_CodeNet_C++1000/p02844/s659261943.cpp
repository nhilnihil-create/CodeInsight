#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int ctoi(char c){
    switch (c){
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        default: return 0;
    }
}

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    int count = 0;
    for (int i = 0; i <= 9; i++){
        for (int j = 0; j <= 9; j++){
            for (int k = 0; k <= 9; k++){
                int cnt = 0;
                int l = 0;
                while (true){
                    if (l == N || cnt == 3){
                        break;
                    }
                    else if (cnt == 0){
                        if (ctoi(S[l]) == i){
                            l++;
                            cnt++;
                        }
                        else{
                            l++;
                        }
                    }
                    else if (cnt == 1){
                        if (ctoi(S[l]) == j){
                            l++;
                            cnt++;
                        }
                        else{
                            l++;
                        }
                    }
                    else if (cnt == 2){
                        if (ctoi(S[l]) == k){
                            l++;
                            cnt++;
                        }
                        else{
                            l++;
                        }
                    }
                }
                if (cnt == 3) count++;
            }
        }
    }
    cout << count << endl;
}
