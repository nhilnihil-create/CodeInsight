#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
#include<map>
#include<cstdlib>



using namespace std;

    string s,t,ans;

    int n;

int main(){

    cin >> n;
    cin >> s >> t;
    int ite=0;
    for(int i=0;i<n;i++){
        cout << s[i];
        cout << t[i];
    }
    cout << endl;

    return 0;
}