    #include <iostream>
    using namespace std;
     
    int main() {
    	int h,w,i,j;
    	for(;;){
    		cin>>h>>w;
    		if (h==0&&w==0){break;}
    		for(i=0;i<h;i++){
    			for(j=0;j<w/2;j++){
    				if(i%2==0){
    					cout<<"#"<<".";
    				}
    				else{
    					cout<<"."<<"#";
    				}
    			}
    			if(w%2==1&&i%2==0){
    				cout<<"#";
    			}
    			if(w%2==1&&i%2==1){
    				cout<<".";
    			}	
    			cout<<endl;
    		}
    		cout<<endl;
    	}
    }
