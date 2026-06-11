#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >>N;
    vector<int>vec(N-1);
    for(int i=0;i<N-1;i++){
        cin >> vec.at(i);
    }
    reverse(vec.begin(),vec.end());
    int count=0;
    for(int i=0;i<N-1;i++){
        if(i==0){
           count += vec.at(0);
           continue;
        }
            count +=min(vec.at(i-1),vec.at(i));
        }
    
            count += vec.at(N-2);
        cout << count <<endl;
}