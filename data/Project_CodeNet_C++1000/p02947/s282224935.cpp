#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<string> s(n);
    for(int i=0; i<n; i++){
        cin >> s.at(i);
        sort(s.at(i).begin(),s.at(i).end());
    }
    
    sort(s.begin(),s.end());

    long long int count=0;
    long long int num=0;
    for(int i=1; i<n; i++){
        if(s.at(i-1)==s.at(i)){
            num++;
            count+=num;
        }
        else num=0;
    }

    cout << count << endl;
}