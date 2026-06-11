#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    for(int i=0; i<N; i++) cin >> a.at(i);
    vector<bitset<30> > b(N);
    for(int i=0; i<N; i++) b.at(i) = a.at(i);
    bitset<30> odd;
    for(int i=0; i<N; i++) odd = odd ^ b.at(i);
    for(int i=0; i<N; i++) b.at(i) = b.at(i) ^ odd;
    for(int i=0; i<N; i++) cout << b.at(i).to_ullong() << endl;
}