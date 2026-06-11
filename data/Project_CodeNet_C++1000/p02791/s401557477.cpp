#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >>N;
    vector<int>vec(N);
    for(int i=0;i<N;i++){
        cin >> vec.at(i);
    }
    int count=9999999;
    int summ=0;
    for(int i=0;i<N;i++){
    count =min(vec.at(i),count);
       if(count>=vec.at(i)){
          summ++;
       }
    }
    cout <<summ<<endl;
}