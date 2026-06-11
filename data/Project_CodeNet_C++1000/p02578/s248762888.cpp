#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int64_t count = 0;
    vector<int> vec(N);
    for (int i = 0; i < N; i++){
        cin >> vec.at(i);
    }
    for(int i = 0; i < N - 1; i++){
        if(vec.at(i) > vec.at(i + 1)){
            count += vec.at(i) - vec.at(i + 1);
            vec.at(i + 1) = vec.at(i);
        }
    }
  cout << count << endl;
}

