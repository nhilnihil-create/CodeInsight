#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<string> S(N);
    for(int i=0; i<N; i++) cin >> S.at(i);
    set<string> Sset;
    int count = 0;
    for(string s : S){
        if(Sset.find(s) == Sset.end()){
            Sset.insert(s);
            count++;
        }
    }
    cout << count << endl;
}