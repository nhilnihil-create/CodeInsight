//
//  triangle.cpp
//  my_programs
//
//  Created by Jiatuo Zou on 7/27/20.
//  Copyright © 2020 Jiatuo Zou. All rights reserved.
//

#include <iostream>
#include <string>

int main()
{
    using namespace std;
    
    int n, counter[99] = {0}, sum = 0;
    string w[200000];
    cin >> n;
    for(int i = 1; i <= n; i++){
        int a = i;
        while(a > 0){
            w[i - 1] = char(a % 10 + '0') + w[i - 1];
            a /= 10;
        }
        if(i > 9){
            counter[(w[i - 1][0] - '0') * 10 + w[i - 1][w[i - 1].length() - 1] - '0' - 1]++;
        } else{
            counter[w[i - 1][0] - '0' - 1]++;
        }
    }
    for(int i = 0; i < n; i++){
        if(w[i][w[i].length() - 1] != '0'){
            if(w[i][0] == w[i][w[i].length() - 1]){
                sum += (counter[(w[i][0] - '0') * 10 + w[i][w[i].length() - 1] - '0' - 1] + counter[w[i][0] - '0' - 1]);
            } else{
                sum += (counter[(w[i][w[i].length() - 1] - '0') * 10 + w[i][0] - '0' - 1]);
            }
        }
    }
    cout << sum << endl;
    return 0;
}
