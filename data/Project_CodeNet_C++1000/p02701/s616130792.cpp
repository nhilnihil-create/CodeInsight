#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
    int n;
    vector<string> name;
    int answer = 0;

    cin >> n;

    string input;
    for(int i = 0; i < n; i++){
        cin >> input;
        name.push_back(input);
    }

    sort(name.begin(),name.end());

    for(int i = 0; i < n; i++){
        if(i==0){
            answer++;
            continue;
        }

        if(name[i].compare(name[i-1]) != 0 ){
            answer++;
        }
    }

    cout << answer;
    
}