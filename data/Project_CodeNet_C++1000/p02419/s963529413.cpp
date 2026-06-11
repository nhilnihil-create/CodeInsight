#include <iostream>
#include <string>
using namespace std;
 
string low(string w){
    string w_ = "";
    for(int i=0;i<w.size();i++){
        if(w[i] >= 'A' && w[i] <= 'Z'){
            w_ += w[i]+32;
        }else{
            w_ += w[i];
        }
    }
    return w_;
}

int main(){
    string w; cin >> w;
    string t;
    string tmp = "";
    int cnt=0;
    int line = 0;
    w = low(w);
    
    string tango = "";

    while(true){
        getline(cin, t);
        if(t=="END_OF_TEXT"){
            if(tango==w){
                cnt += 1;
            }
            break;
        }
        t = low(t);

        // for(int i=0;i<t.size();i++){
        //     if(i==0){
        //         if(tmp==w){
        //             cnt++;
        //         }
        //         tmp="";
        //     }
            
        //     if(t[i]!=' '){
        //         tmp += t[i];
        //     }else{
        //         if(tmp==w){
        //             cnt++;
        //         }
        //         tmp="";
        //     }
        // }
        for(int i=0;i<t.size();i++){
            if(i==0){
                if(tango==w){
                    cnt += 1;
                }
                tango = "";
            }
            
            if(t[i]!=' '){
                tango += t[i];
            }else{
                if(tango==w){
                    cnt += 1;
                }
                tango = "";
            }
        }
        // cout << cnt<< endl;
        
    }

    cout << cnt<< endl;
    return 0;
}
