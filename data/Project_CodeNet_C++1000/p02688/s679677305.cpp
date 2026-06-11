#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> d(K);
    vector<int> sunuke(N, 0);
    vector<vector<int> > A(K, vector<int>(N));
    int i, j;
    
    for(i=0;i<K;i++){
        cin >> d.at(i);
        for(j=0;j<d.at(i);j++){
            cin >> A.at(i).at(j);
            sunuke.at(A.at(i).at(j)-1) += 1;
        }
    }
    int ans=0;
    for(i=0;i<N;i++){
        if(sunuke.at(i)==0)
            ans++;
    }
    cout << ans << endl;

}