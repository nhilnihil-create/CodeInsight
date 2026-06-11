#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main () {
    while (true) {
        //input
        string init_str;
        cin >> init_str;
        if (init_str == "-") break;
        
        int times;
        cin >> times;

        string result = init_str;
        for (int i=0; i<times; i++) {
            int num = 0;
            cin >> num;

            // think
            int strlen = init_str.size();
            result
                = result.substr(num,strlen-num) 
                + result.substr(0,num);
        }
        //output
        cout << result << endl;
    }
}
