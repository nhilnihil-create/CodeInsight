#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    vector <string> day = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
    for(int i = 0; i < day.size(); i++){
        if(s.compare(day[i])==0){
            cout << day.size()-i << endl;
        }
    }
    return 0;
}