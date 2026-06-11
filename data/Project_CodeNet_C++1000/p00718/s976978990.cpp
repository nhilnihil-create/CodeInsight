#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    for(int i=0; i<n; i++){

        string l,r;

        cin >> l >> r;

        int le = 0, ri = 0;

        for(int i=0; i<l.size(); i++){
            if(isdigit(l[i])){
                int tmp = l[i] - '0';
                i++;
                if(l[i] == 'm'){
                    tmp *= 1000;
                }
                else if(l[i] == 'c'){
                    tmp *= 100;
                }
                else if(l[i] == 'x'){
                    tmp *= 10;
                }
                else if(l[i] == 'i'){
                    tmp *= 1;
                }
                le += tmp;
            }
            else{
                if(l[i] == 'm'){
                    le += 1000;
                }
                else if(l[i] == 'c'){
                    le += 100;
                }
                else if(l[i] == 'x'){
                    le += 10;
                }
                else if(l[i] == 'i'){
                    le += 1;
                }
            }
        }

        for(int i=0; i<r.size(); i++){
            if(isdigit(r[i])){
                int tmp = r[i] - '0';
                i++;
                if(r[i] == 'm'){
                    tmp *= 1000;
                }
                else if(r[i] == 'c'){
                    tmp *= 100;
                }
                else if(r[i] == 'x'){
                    tmp *= 10;
                }
                else if(r[i] == 'i'){
                    tmp *= 1;
                }
                ri += tmp;
            }
            else{
                if(r[i] == 'm'){
                    ri += 1000;
                }
                else if(r[i] == 'c'){
                    ri += 100;
                }
                else if(r[i] == 'x'){
                    ri += 10;
                }
                else if(r[i] == 'i'){
                    ri += 1;
                }
            }
        }

        int ans_num = le + ri;
        string ans = "";

        if(ans_num >= 1000){
            int tmp = ans_num/1000;
            ans_num = ans_num%1000;
            stringstream ss;
            string s;
            ss << tmp;
            ss >> s;
            if(s == "1"){
                s = "";
            }
            ans += s + 'm';
        }

        if(ans_num >= 100){
            int tmp = ans_num/100;
            ans_num = ans_num%100;
            stringstream ss;
            string s;
            ss << tmp;
            ss >> s;
            if(s == "1"){
                s = "";
            }
            ans += s + 'c';
        }

        if(ans_num >= 10){
            int tmp = ans_num/10;
            ans_num = ans_num%10;
            stringstream ss;
            string s;
            ss << tmp;
            ss >> s;
            if(s == "1"){
                s = "";
            }
            ans += s + 'x';
        }

        if(ans_num >= 1){
            int tmp = ans_num/1;
            ans_num = ans_num%1;
            stringstream ss;
            string s;
            ss << tmp;
            ss >> s;
            if(s == "1"){
                s = "";
            }
            ans += s + 'i';
        }

        cout << ans << endl;

    }

    return 0;
}
