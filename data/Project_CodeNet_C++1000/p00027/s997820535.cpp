#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
    int month[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string week[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int m, d, start, count;
    while(cin >> m >> d){
        if(m==0) break;
        start = 1;
        count = 3;
        while(1){
            for(int i=1 ; i <= month[start-1] ; i++, count++){
                if(m==start && d==i) break;
            }
            if(m==start) break;
            start++;
        }
        cout << week[count%7] << endl;
    }
    return 0;
}