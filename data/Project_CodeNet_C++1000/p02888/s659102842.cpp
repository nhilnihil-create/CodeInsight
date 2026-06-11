//
//  triangle.cpp
//  my_programs
//
//  Created by Jiatuo Zou on 7/27/20.
//  Copyright © 2020 Jiatuo Zou. All rights reserved.
//

#include <iostream>
#include <algorithm>

int main()
{
    using namespace std;
    
    int n, l[2000], sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> l[i];
    }
    sort(l, l + n);
    for(int i = 0; i < n - 2; i++){
        for(int j = i + 1, k = i + 2; j < n - 1; ){
            if(k < n && l[k] < l[i] + l[j]){
                k++;
            } else{
                sum += (k - j - 1);
                j++;
            }
        }
    }
    cout << sum << endl;
    return 0;
}
