#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> array(n),parray(n),qarray(n);
    for(int i=0;i<n;i++) cin >> parray.at(i);
    for(int i=0;i<n;i++) cin >> qarray.at(i);
    int num = 1;
    for(int i=0;i<n;i++){
        array.at(i) = num;
        num++;
    }

    int cnt = 0,p=0,q=0;
    while(next_permutation(array.begin(),array.end())){
        cnt ++;
        if(array == parray) p = cnt;
        if(array == qarray) q = cnt;
        //next_permutation(array.begin(),array.end());
    }
    //cout << p << " " << q << endl;
    cout << abs(p-q) << endl;
}