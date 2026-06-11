#include <bits/stdc++.h>
using namespace std;

int main(){
    int64_t N, D, count;
    cin >> N >> D;
    count = 0;
    vector<int64_t> vec1(N), vec2(N);
    for (int i = 0; i < N; i++){
        cin >> vec1.at(i) >> vec2.at(i);
    }
    for (int i = 0; i < N; i++){
        if (D * D >= vec1.at(i) * vec1.at(i) + vec2.at(i) * vec2.at(i))
            count++;
    }
    cout << count << endl;
}