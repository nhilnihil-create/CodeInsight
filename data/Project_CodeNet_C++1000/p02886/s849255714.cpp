#include <iostream>
#include <vector>
using namespace std;

int main() {
 int N;
 cin >> N;
 vector <int> szamook;
 int seged;
 for(int i=0;i<N;i++){
   cin >> seged;
   szamook.push_back(seged);
 }
 seged=0;
 for(int i=0;i<szamook.size()-1;i++){
   for(int j=i+1;j<szamook.size();j++){
     seged+=szamook[i]*szamook[j];
   }
 }
 cout << seged;
	return 0;
}
