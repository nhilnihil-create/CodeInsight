#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    
    vector <int> vec(N+1);

    for(int i=1;i<=N;i++){
        cin >> vec[i];
    }

    int count = 0;
    for(int i=1;i<=N;i++){
        if(i%2 == 1 && vec[i]%2 == 1)
        count++;
    }
    cout << count << endl;
}