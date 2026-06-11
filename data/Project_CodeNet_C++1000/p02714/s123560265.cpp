//
//  AAAAAB.cpp
//  my_programs
//
//  Created by Jiatuo Zou on 7/22/20.
//  Copyright © 2020 Jiatuo Zou. All rights reserved.
//

#include <iostream>
#include <string>

int main()
{
    using namespace std;
    
    int n;
    long long int sum = 0, prefix_sum[4001][3] = {{0}};
    string s;
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        if(s[i] == 'R'){
            prefix_sum[i + 1][0]++;
        } else if(s[i] == 'G'){
            prefix_sum[i + 1][1]++;
        } else{
            prefix_sum[i + 1][2]++;
        }
        prefix_sum[i + 1][0] += prefix_sum[i][0];
        prefix_sum[i + 1][1] += prefix_sum[i][1];
        prefix_sum[i + 1][2] += prefix_sum[i][2];
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(s[j] != s[i]){
                if(s[j] == 'R' && s[i] == 'G' || s[j] == 'G' && s[i] == 'R'){
                    sum += (prefix_sum[n][2] - prefix_sum[j][2]);
                } else if(s[j] == 'R' && s[i] == 'B' || s[j] == 'B' && s[i] == 'R'){
                    sum += (prefix_sum[n][1] - prefix_sum[j][1]);
                } else{
                    sum += (prefix_sum[n][0] - prefix_sum[j][0]);
                }
                if(j + j - i < n && s[j + j - i] != s[j] && s[i] != s[j + j - i]){
                    sum--;
                }
            }
        }
    }
    cout << sum << endl;
    return 0;
}
