#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<string> S(N);
    for(int i=0; i<N; i++){
        cin >> S[i];
    }

    sort(S.begin(), S.end());
    string target = S[0];
    int max_count =0;
    int count =0;
    
    for(int i=0; i<N; i++){
        if(target == S[i]){
            count++;
        }

        if(i==(N-1) || target != S[i]){
            if(max_count < count){max_count=count;}
            target = S[i];
            count = 1;
        }
    }

    count = 0;
    target = S[0];
    for(int i=0; i<N; i++){
        if(target == S[i]){
            count++;
        }

        if(i==(N-1) || target != S[i]){
            if(count == max_count){
                cout << target << "\n";
            }
            target = S[i];
            count = 1;
        }
    }

    if(count == max_count){
        cout << target << "\n";
    }


    return 0;

}