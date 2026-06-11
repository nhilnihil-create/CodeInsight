//
//  blue and red.cpp
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
    
    int x, y, a, b, c;
    long long int p[100000], q[100000], r[100000], combined[200000], sum = 0;
    cin >> x >> y >> a >> b >> c;
    for(int i = 0; i < a; i++){
        cin >> p[i];
    }
    for(int i = 0; i < b; i++){
        cin >> q[i];
    }
    for(int i = 0; i < c; i++){
        cin >> r[i];
    }
    sort(p, p + a);
    sort(q, q + b);
    sort(r, r + c);
    for(int i = a - 1; i >= a - x; i--){
        combined[a - 1 - i] = p[i];
    }
    for(int i = b - 1; i >= b - y; i--){
        combined[x + b - 1 - i] = q[i];
    }
    sort(combined, combined + x + y);
    for(int i = 0; i < x + y; i++){
        if(c - 1 - i >= 0 && combined[i] < r[c - 1 - i]){
            combined[i] = r[c - 1 - i];
        }
    }
    for(int i = 0; i < x + y; i++){
        sum += combined[i];
    }
    cout << sum << endl;
    return 0;
}
