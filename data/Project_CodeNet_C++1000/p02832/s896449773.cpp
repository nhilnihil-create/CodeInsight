#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >>N;
    vector<int>vec(N);
    for(int i=0;i<N;i++){
        cin >> vec.at(i);
    }
    int count=1;
    int block=0;
    for(int i=0;i<N;i++){
       if(vec.at(i)==count){
           count++;
           block++;
       }

    }
    if(block==0){
        cout <<-1<<endl;
        
    }
    else{
    cout << N-block<<endl;
    }
}