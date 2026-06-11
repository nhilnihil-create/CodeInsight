#include <bits/stdc++.h>

using namespace std;

int main()
{
    string input;
    int c = 0;
    cin >> input;
    int sz = input.size();
    for(int i = 0; i < sz; i += 2){
        if(sz%2 == 0){
            if(input[i] == 'R' || input[i] == 'U' || input[i] == 'D'){
                if(input[i+1] == 'L' || input[i+1] == 'U' || input[i+1] == 'D'){
                    c++;
                }
            }
        }
        else if(sz%2 != 0){
            if(i < sz-1){
                if(input[i] == 'R' || input[i] == 'U' || input[i] == 'D'){
                    if(input[i+1] == 'L' || input[i+1] == 'U' || input[i+1] == 'D'){
                        c++;
                }
            }
            }
            else{
                if(input[i] == 'R' || input[i] == 'U' || input[i] == 'D'){
                    c++;
                }
            }
        }
    }
    double e = sz / 2.0;
    if(c == ceil(e)){
        cout << "Yes" << "\n";
    }
    else{
        cout << "No" << "\n";
    }

    return 0;
}