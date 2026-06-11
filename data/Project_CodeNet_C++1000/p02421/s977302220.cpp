#include<iostream>
#include<string>

using namespace std;

int main () {
    int i, n, taro=0, hanako=0;
    string t, h;
    cin >> n;
    for(i=0;i<n;i++) {
        cin >> t >> h;
        if(t.compare(h) > 0) taro+=3;
        else if(t.compare(h) < 0) hanako+=3;
        else {taro++; hanako++;}
    }
    cout << taro << " " << hanako <<endl;
}