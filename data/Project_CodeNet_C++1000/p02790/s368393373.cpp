#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<numeric>

using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    vector<string> vec;
    vec.push_back(a);
    vec.push_back(b);

    sort(vec.begin(),vec.end());


    for(int i = 0; i < stoi(vec[1]); i++){
        cout << vec[0];
    }

}