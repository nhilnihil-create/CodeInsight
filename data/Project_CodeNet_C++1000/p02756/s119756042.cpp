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
    
    int q, t, f, total = 0;
    string s;
    char c;
    cin >> s >> q;
    for(int i = 0; i < q; i++){
        cin >> t;
        if(t == 2){
            cin >> f >> c;
            if(total % 2 == 0){
                f == 1 ? s = c + s : s += c;
            } else{
                f == 1 ? s += c : s = c + s;
            }
        } else{
            total++;
        }
    }
    if(total % 2 == 0){
        cout << s << endl;
    } else{
        for(int i = s.length() - 1; i >= 0; i--){
            cout << s[i];
        }
        cout << endl;
    }
    return 0;
}
