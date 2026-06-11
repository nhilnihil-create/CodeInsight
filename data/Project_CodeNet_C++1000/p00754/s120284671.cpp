 #include <bits/stdc++.h>
 using namespace std;

 int main(){

   string str;

   while(1){

     getline(cin, str);
     if(str[0] == '.') break;

     vector<char> v;

     for(int i = 0; i < (int)str.size(); i++){
       if(str[i] == '[' || str[i] == '('){
	 v.push_back(str[i]);
       }else if(str[i] == ')'){
	 if(v.empty()){
	   v.push_back(str[i]);
	   break;
	 }

	   if(v.back() == '('){
	     v.pop_back();
	   }else break;

       }else if(str[i] == ']'){
	 if(v.empty()){
	   v.push_back(str[i]);
	   break;
	 }

	   if(v.back() == '['){
	     v.pop_back();
	   }else break;
       }
     }
     if(v.empty()) cout << "yes" << endl;
     else cout << "no" << endl;

   }

   return 0;
 }