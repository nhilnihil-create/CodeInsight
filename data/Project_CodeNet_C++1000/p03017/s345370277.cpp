#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <map>
#include <array>
#include <cmath>

using namespace std;

long long PRIME = 1000000007;


bool check(string& s, int start, int end){
    int count = 0;

    for(int i = start; i <= end; ++i){
        if(s[i - 1] == '#'){
            ++count;
            if(count == 2){
                return false;
            }
        }
        else{
            count = 0;
        }
    }

    return true;
}


int main(int argc, char* argv[]){
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;

    string S;
    cin >> S;

    if(!check(S, B, D) || !check(S, A, C)){
        cout << "No";
        return 0;
    }

    if(C < D){
        cout << "Yes";
    }
    else{
        int count = 0;
        for(int i = B - 1; i <= D + 1; ++i){
            if(S[i - 1] == '.'){
                ++count;
                if(count == 3){
                    cout << "Yes";
                    return 0;
                }
            }
            else{
                count = 0;
            }
        }

        cout << "No";
    }

}
