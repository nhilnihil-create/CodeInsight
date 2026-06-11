#include<bits/stdc++.h>
using namespace std;

int main(){

    int N,X;
    int input;
    cin >> N >> X;
    cin >> input;
    vector<int> v;
    vector<int> steps;
    steps.push_back(0);
    v.push_back(input);
    int D_last = 0;
    int L_last = v[0];
    for(int i=1;i<N;i++){
        cin >> input;
        v.push_back(input);
    }

    for(int i=0;i<N;i++){
        steps.push_back(D_last+L_last);
        D_last = D_last+L_last;
        L_last = v[i+1];
    }

    int result = 0;
    for(int i=0;i<steps.size();i++){
        if(steps[i] <= X){
            result++;
        }
    }

    cout << result;

}
