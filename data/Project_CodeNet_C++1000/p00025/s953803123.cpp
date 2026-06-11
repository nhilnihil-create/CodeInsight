    #include <iostream>
    using namespace std;
     
    int main() {
    string a,b;
    while(getline(cin,a),getline(cin,b)){
    int hit=0,blow=0;
    for(int i=0;i<a.size();i+=2){
    if(a[i]==b[i]){
    hit++;
    }else if(b.find(a[i],0)!=string::npos){
    blow++;
    }
    }
    cout<<hit<<" "<<blow<<endl;
    }return 0;
    }