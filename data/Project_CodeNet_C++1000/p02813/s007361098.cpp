#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b;
    cin >> n;
    bool flag_a = 0, flag_b = 0;
    vector<int> data_a(n);
    vector<int> data_b(n);
    vector<int> junretu(n);
    for (int i = 0; i < n; i++){
        cin >> data_a.at(i);
        junretu.at(i) = i+1;
    }
    for (int i = 0; i < n; i++){
        cin >> data_b.at(i);
    }
    int i = 1;
    do {
        if(data_a == junretu){
            a = i;
            flag_a = 1;
        }
        if(data_b == junretu){
            b = i;
            flag_b = 1;
        }
        if(flag_a && flag_b)break;
        i++;
    } while (next_permutation(junretu.begin(), junretu.end()));

    cout << abs(a - b) << endl;
}